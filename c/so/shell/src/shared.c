/* 
 *  AUTORES:
 * 	* Carlos Pérez Ramil
 * 	* Rodrigo Arias Mallo
 * 
 *  GRUPO:
 * 	2.3.2
 * 
 *  HORARIO:
 * 	Viernes de 8:30 a 10:30
 */

#include "shared.h"
#include "mem.h"
#include "global.h"
#include "../lib/mblock.h"
#include "../lib/list.h"

void free_mblock_shared(void *pos)
{
	struct mblock_t *element = (struct mblock_t *)pos;
	if (shmctl(element->shmid, IPC_RMID, NULL)==-1) 
		perror("shmctl: no se pudo eliminar memoria compartida");
}

int cmd_shared(char **arg)
{
	if (arg[1]==NULL) {
		list_mem_print(MTYPE_SHARED);
		return 0;
	}
	if (arg[1]==IPC_PRIVATE) {
		printf("Error: clave no válida");
		return -1;
	}
	
	int shmid;
	struct shmid_ds s;
	void *shmaddr;
	time_t t;
	key_t key = (key_t)strtoul(arg[1], NULL, 10);
	size_t size = 0;
	int flags = 0777;
	
	if (arg[2]!=NULL) {
		flags = flags | IPC_CREAT | IPC_EXCL;
		size = atol(arg[2]);
	}
	
	if ((shmid = shmget(key, size, flags))==-1) {
		perror("shmget");
		return -1;
	}
	
	t = time(0);
	if ((shmaddr = shmat(shmid, NULL, 0)) == (void *)-1) {
		perror("shmat");
		if (arg[2]!=NULL) 
			shmctl(shmid, IPC_RMID, NULL);
		return -1;
	}
	
	shmctl(shmid, IPC_STAT, &s);
	size = s.shm_segsz;
	
	struct mblock_t *b = malloc(sizeof(struct mblock_t));
	if(b==NULL) {
		perror("malloc ha fallado");
		return -1;
	}	
	b->addr = shmaddr;
	b->size = size;
	b->time = t;
	b->type = MTYPE_SHARED;
	b->key = key;
	b->shmid = shmid;
		
	if (list_insert(list_mem, b, free_mblock_shared, cmp_mblock)) {
		perror("No se ha podido insertar en la lista");
		return -1;
	}
	
	printf("%p\n", shmaddr);

	return 0;
}
