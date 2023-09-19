#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


/* the write and read  buffers */
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1

/* convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* using system getline() */
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096
#define USE_GETLINE 0
#define USE_STRTOK 0

extern char **environ;

/* chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define INFO_INIT \
{NULL, 0, 0, 0, NULL, NULL}

/**
 * struct liststr - A function that does a single linked list
 * @num: number to filde
 * @next: points to node
 * @str: the string
 */

typedef struct liststr
{
	char *str;
	int num;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contain pseudo-arguments to be passed to a function
 * @arg: String created from getline() with arguments
 * @path: a string path for command the current
 * @line_count: error count
 * @err_num: error code to exit()
 * @argc: the argument from arg
 * @argv: An array of strings created from arg
 * @linecount_flag: count this line to input
 * @history: history node
 * @env_changed: environ was changed
 * @fname: filename
 * @env: linked list to environ
 * @cmd_buf:pointer to cmd_buffer, on if chain
 * @cmd_buf_type: ||, &&, ; CMD_TYBE
 * @environ: copy of environ
 * @histcount: the history line
 * @status: the return status
 * @alias: alias node
 * @readfd: the fd from read  input
 */

typedef struct passinfo
{
	char *arg;
	char *path;
	unsigned int line_count;
	int err_num;
	int argc;
	char **argv;
	int linecount_flag;
	list_t *history;
	int env_changed;
	char *fname;
	list_t *env;
	char **cmd_buf; /* pointer to cmd ; chain buffer, memotry mangement */
	int cmd_buf_type; /* &&, CMD_type || ; */
	char **environ;
	int histcount;
	int status;
	list_t *alias;
	int readfd;
} info_t;

/**
 * struct builtin - Contains built-in String and related post
 * @type: builtin command
 * @func: function to builtin
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char *_strncpy(char *, char *, int);
char **strtow(char *, char *);
char **strtow2(char *, char);

/*_realloc_fun.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory_fun.c */
int bfree(void **);

/* atoi_fun.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* error_fun.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
void _eputs(char *);
int _putsfd(char *str, int fd);
int _eputchar(char);
int _putfd(char c, int fd);

/* builtin_fun.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);
int _myhistory(info_t *);
int _myalias(info_t *);

/* environ */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* get_line */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* get_environ */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* get_info */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* history */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* list.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loop */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);
int loophsh(char **);

/* var */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif

