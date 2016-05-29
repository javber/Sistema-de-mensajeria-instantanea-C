/*******************************************************************************
 *	friends.h
 *
 *  Client friend list
 *
 *
 *  This file is part of PSD-IMS
 * 
 *  Copyright (C) 2015  Daniel Pinto Rivero, Javier Bermúdez Blanco
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ********************************************************************************/

#ifndef __FRIENDS
#define __FRIENDS

#include "list.h"


typedef struct friend_info friend_info;
struct friend_info{
	char *name;
	char *information;
};

typedef struct friend_list_info friend_list_info;
struct friend_list_info {
	int timestamp;
};

typedef list friends;
typedef list_iterator fri_iterator;

/* =========================================================================
 *  Structs access
 * =========================================================================*/

#define fri_get_name(friend_info) \
		(friend_info->name)

#define fri_get_information(friend_info) \
		(friend_info->information)

#define fri_get_num_friends(friends) \
		list_num_elems(friends)	

#define fri_get_timestamp(friends, friends_timestamp) \
	do{ \
		friend_list_info *aux; \
		aux = list_info(friends); \
		friends_timestamp = aux->timestamp; \
	}while(0)

#define fri_set_timestamp(friends, friends_timestamp) \
	do{ \
		friend_list_info *aux; \
		aux = list_info(friends); \
		aux->timestamp = friends_timestamp; \
	}while(0)


/* =========================================================================
 *  Friends iterator
 * =========================================================================*/
#define fri_get_friends_iterator(list) \
		(fri_iterator*)list_iterator(list)

#define fri_iterator_next(list, iterator) \
		(fri_iterator*)list_iterator_next(list, iterator)

#define fri_get_info(iterator) \
		(friend_info*)list_iterator_info(iterator)


/* =========================================================================
 *  Friend struct API
 * =========================================================================*/

/*
 * Allocates a new friend list
 * Returns a pointer to the list or NULL if fails
 */
friends *fri_new(int max);

/*
 * Frees the friend list
 */
void fri_free(friends *friends);

/*
 * Prints all friends line by line
 */
void fri_print_friend_list(friends *friends);

/*
 * Creates a new friend_node in the list with the provided info
 * Returns 0 or -1 if fails
 */
int fri_add_friend(friends *friends, const char *name, const char *information);

/*
 * Removes and frees the first node that matches the provided "name"
 * Returns 0 or -1 if "name" does not exist in the list
 */
int fri_del_friend(friends *friends, const char *name);

/*
 * Finds the chat whos id is chat_id
 * Returns a pointer to the chat_info of NULL if fails
 */
friend_info *fri_find_friend(friends *friends, const char *name);


#endif /* __FRIENDS */
