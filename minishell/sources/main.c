#include "../includes/minishell.h"

char    *ft_strjoin_del(char *s1, char *s2){
	char *new;
	new = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (new);
}


int	    space_checker(int c){
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}


int     ft_permission_check(char *str){
	if (access(str, F_OK) != 0){
		ft_putstr(str);
		ft_putendl(": Command not found.");
		return (0);
	}
	else if (access(str, X_OK) != 0){
		ft_putstr(str);
		ft_putendl(": Permission denied");
		return (0);
	}
	return (1);
}

int		ft_permission_check_f(char *str){
	if (access(str, F_OK) != 0){
		ft_putstr(str);
		ft_putendl(": Does not exist.");
		return (0);
	} else if (access(str, X_OK) != 0){
		ft_putstr(str);
		ft_putendl(": Permission denied");
		return (0);
	}
	return (1);
}


static void	injector(char *value, char **str, char *ptr){
	char new[_POSIX_ARG_MAX];
	char *check;

	ft_bzero(new, _POSIX_ARG_MAX);
	ft_memcpy(new, *str, ptr - *str);
	if (value)
		ft_strcat(new, value);
	else{
		if (!ptr[1])
			ft_strcat(new, "$");
	}
	if ((check = ft_strchr(ptr, ' ')))
		ft_strcat(new, check);
	ft_strdel(str);
	*str = ft_strdup(new);
	ft_strdel(&value);
}

static void	args_checker_parse(char **str){
	int		j;
	char	*ptr;
	char	*temp;
	char	*value;
	char	*word;

	j = 0;
	ptr = NULL;
	while ((*str)[j]){
		if ((ptr = ft_strchr(&(*str)[j], '$')) && (*str)[0]){
			if (!(word = ft_strchr(ptr, ' ')))
				word = ft_strchr(ptr, '\0');
			j = (ptr - *str) + 1;
			temp = ft_strsub(ptr, 1, word - (ptr + 1));
			value = ft_find_param(g, temp, NULL, S_VAL);
			injector(value, str, ptr);
			ft_strdel(&temp);
		} else
			j++;
	}
}

void		args_checker(char **args)
{
	if (!args || !*args || !**args)
		return ;
	if (args[1])
		args++;
	else
		return ;
	while (*args){
		args_checker_parse(args);
		args++;
	}
}


int		ft_chdir(char *path){
	char	prev_pwd[PATH_MAX];
	char	curr_pwd[PATH_MAX];
	int		del;
	del = 0;
	if (!path){
		path = ft_find_param(g, "HOME", NULL, S_VAL);
		del = 1;
	}
	else if (ft_strcmp(path, "-") == 0){
		path = ft_find_param(g, "OLDPWD", NULL, S_VAL);
		del = 1;
	}
	if (!ft_permission_check_f(path))
		return (1);
	getcwd(prev_pwd, PATH_MAX);

	ft_setstrstr("OLDPWD", prev_pwd, ft_strlen("OLDPWD"), ft_strlen(prev_pwd));

	chdir(path);
	getcwd(curr_pwd, PATH_MAX);
	ft_setstrstr("PWD", curr_pwd, ft_strlen("PWD"), ft_strlen(curr_pwd));
	if (del)
		free(path);
	return (1);
}


int				ft_print_echo(char **args){
	char	flag;
	int		i;
	flag = 0;
	i = 0;
	args++;
	if (*args && (*args)[i++] == '-'){
		while ((*args)[i] == 'n')
			i++;
		if (!(*args)[i]){
			flag = 'n';
			args++;
		}
	}
	while (*args){
		ft_putstr(*args++);
		if (*args)
			ft_putchar(' ');
	}
	if (!flag)
        ft_putchar('\n');
	return (1);
}


static void	ft_change_env(char *value, size_t vallen, char *newstr, int index){
	char	*original_val;
	char	*temp;
	original_val = ft_strchr(g[index], '=') + 1;
	if (!original_val)
		return ;
	else if (ft_strlen(original_val) >= vallen)
		ft_strcpy(original_val, value);
	else{
		temp = ft_strdup(newstr);
		free(g[index]);
		g[index] = temp;
	}
}

void		ft_setstrstr(char *var, char *value, size_t varlen, size_t vallen){
	char	newstr[varlen + vallen + 2];
	int		i;

	if (!var || !value || !*var || !*value)
		print_error("Incorrect setenv format", 0);
	i = 0;
	while (g[i]){
		if (!ft_strncmp(g[i], var, varlen) && (g[i][varlen] == '='))
			break ;
		i++;
	}
	ft_bzero(newstr, sizeof(newstr));
	ft_strcat(newstr, var);
	ft_strcat(newstr, "=");
	ft_strcat(newstr, value);
	if (g[i])
		ft_change_env(value, vallen, newstr, i);
	else
		g = ft_strstr_remalloc(g, newstr);
}

int		ft_parse_setenv(char **args){
	if (ft_strstrlen(args) != 3)
		print_error("Arguments invalid", 0);
	else
		ft_setstrstr(args[1], args[2], ft_strlen(args[1]), ft_strlen(args[2]));
	return (1);
}


char	**ft_dupstrstr(char **arr){
	char	**dup;
	char	**dup_z;
	size_t	len;

	if (!(len = ft_strstrlen(arr)))
		return (NULL);
	if (!(dup = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	dup_z = dup;
	dup[len] = NULL;
	while (len--)
		*dup++ = ft_strdup(*arr++);
	return (dup_z);
}


size_t		ft_strstrlen(char **ss){
	size_t i;

	i = 0;
	if (ss)
		while (ss[i])
			i++;
	return (i);
}


char	**ft_strstr_remalloc(char **arr, char *str){
	char	**new;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strstrlen(arr);
	new = (char**)malloc(sizeof(char*) * (len + 2));
	new[len + 1] = NULL;
	while (len--){
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	ft_delstrstr(&arr);
	return (new);
}


void	ft_delstrstr(char ***del_me){
	int i;

	i = 0;
	while ((*del_me)[i])
		free((*del_me)[i++]);
	free(*del_me);
}


void	ft_unsetstrstr(char *varname){
	int		i;
	size_t	vlen;

	i = 0;
	vlen = ft_strlen(varname);
	while (g[i]){
		if (!ft_strncmp(g[i], varname, vlen) && g[i][vlen] == '=')
			break ;
		i++;
	}
	if (g[i]){
		free(g[i]);
		g[i] = NULL;
		while (g[++i])
			g[i - 1] = g[i];
		g[i - 1] = NULL;
	}
}

int		ft_parse_unsetenv(char **args){
	if (args[1])
		ft_unsetstrstr(args[1]);
	else
		print_error("No arguments.", 0);
	return (1);
}


static void	print_err_exit(void){
	ft_putendl(": a fatal error occured: shell terminated.");
	if (g && *g)
		ft_delstrstr(&g);
	exit(EXIT_FAILURE);
}

void		print_err_delstrstr(char *err, char ***arrdel, int f){
	ft_putendl(err);
	if (arrdel && *arrdel){
		ft_delstrstr(arrdel);
		**arrdel = NULL;
	}
	if (f)
		print_err_exit();
}

void		print_error(char *err, int f){
	ft_putendl(err);
	if (f)
		print_err_exit();
}


static char	*scan_binaries(char *path, char *arg, int n){
	struct dirent	*bins;
	DIR				*path_to_bin;
	char			location[n + 2];
	ft_strncpy(location, path, n);
	location[n] = '/';
	location[n + 1] = 0;
	path_to_bin = opendir(location);
	if (path_to_bin == NULL)
		return (NULL);
	while ((bins = readdir(path_to_bin)) != NULL){
		if (ft_strcmp(bins->d_name, arg) == 0){
			closedir(path_to_bin);
			return (ft_strdup(location));
		}
		bins++;
	}
	if (closedir(path_to_bin) == -1)
		print_error("Directory Error", 1);
	return (NULL);
}

static char	*scan_path(char *arg, char *start, char *end){
	char	*path;
	if ((path = scan_binaries(start, arg, end - start)))
		return (path);
	while (!path){
		start = end;
		if (*start == 0)
			return (NULL);
		start += 1;
		if (!(end = ft_strchr(start, ':')))
			end = ft_strchr(start, 0);
		path = scan_binaries(start, arg, end - start);
		if (path)
			return (path);
	}
	return (NULL);
}

static char	*ft_get_path(char *var, char *arg, int flag){
	char	*start;
	char	*end;
	start = ft_strchr(var, '=');
	if (start){
		if (flag & S_VAL)
			return (ft_strdup(start + 1));
		if (!(end = ft_strchr(start + 1, ':')))
			end = ft_strchr(start, 0);
		return (scan_path(arg, start + 1, end));
	}
	return (NULL);
}

static char	*scan_env(char **env, char *env_var, char *arg, int flag){
	int		i;
	int		len;

	i = 0;
	while (env[i]){
		len = ft_strlen(env_var);
		if (ft_strncmp(env[i], env_var, len) == 0 && (env[i][len] == '=')){
			if (!flag)
				return (ft_strdup(env[i]));
			else if (flag)
				return (ft_get_path(env[i], arg, flag));
		}
		i++;
	}
	return (NULL);
}

char		*ft_find_param(char **env, char *env_var, char *arg, int flag){
	if (!env || !*env || !env_var || !*env_var)
		return (NULL);
	return (scan_env(env, env_var, arg, flag));
}


static void	ft_clean_q(char *p){
	char	f;
	int		i;
	f = 0;
	while (p && *p){
		i = 0;
		while (*p && *p != '"' && *p != '\'')
			p++;
		if (*p == '"' || *p == '\''){
			if (f == 0)
				f = *p;
			else if (f == *p)
				f = 0;
		}
		if (f == *p || f == 0)
			while (p && p[i++])
				p[i - 1] = p[i];
		else
			p++;
	}
}

static void	parse_q(char **input, char *f){
	while (**input && !(space_checker(**input) && *f == 0)){
		if (**input == '\'' || **input == '"'){
			if (*f == **input)
				*f = 0;
			else if (*f == 0)
				*f = **input;
		}
		(*input)++;
	}
}

static void	ft_tilde_expansion(char **str){
	char *home;
	char *temp;
	home = ft_find_param(g, "HOME", NULL, S_VAL);
	temp = ft_strjoin_del(home, &(*str)[1]);
	ft_strdel(str);
	*str = temp;
}

static void	ft_inp_parser(char **args, char *input, char *f){
	char	*ip;
	char	*op;
	int		i;

	i = 0;
	while (*input){
		ip = input;
		parse_q(&input, f);
		op = input;
		if (!(args[i] = ft_strsub(ip, 0, op - ip))){
			print_err_delstrstr("Memory Error", &args, 0);
			return ;
		}
		if (args[i][0] == '~' && (!args[i][1] || args[i][1] == '/'))
			ft_tilde_expansion(&args[i]);
		ft_clean_q(args[i]);
		i++;
		while (space_checker(*input))
			input++;
	}
	args[i] = NULL;
}

char		**inp_handler(char *input)
{
	char	**args;
	char	f;
	f = 0;
	if (!input || !*input)
		return (NULL);
	if (!(args = (char**)malloc(sizeof(char*) * (_POSIX_ARG_MAX)))){
		print_error("Memory Error", 0);
		return (NULL);
	}
	ft_inp_parser(args, input, &f);
	if (f){
		ft_putendl("Error: unmatched qoutes.");
		if (args && *args)
			ft_delstrstr(&args);
		return (NULL);
	}
	return (args);
}


int	print_strstr(char **ss){
	int	i;
	i = 0;
	while (ss[i])
		ft_putendl(ss[i++]);
	return (1);
}


static void	ft_getenvpath(char **args, char **path){
	char *tmp;
	if (!(tmp = ft_find_param(g, "PATH", args[0], S_ON))){
		*path = args[0];
		return ;
	}
	else
		tmp = ft_strjoin_del(tmp, args[0]);
	ft_strcpy(*path, tmp);
	free(tmp);
}

static int	launch_execve(char **args, int ok){
	char	tmp_path[PATH_MAX];
	pid_t	pid;
	char	*path;

	path = tmp_path;
	ft_getenvpath(args, &path);
	if (!ft_permission_check(path))
		return (1);
	pid = fork();
	if (pid == 0){
		execve(path, args, g);
		ft_putstr("Error opening: ");
		ft_putendl(*args);
		exit(EXIT_FAILURE);
	}
	wait(&ok);
	return (1);
}

static int	launch(char **args){
	int		status;
	status = 1;
	if (!args || !*args || !**args)
		return (1);
	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	else if (ft_strcmp(*args, "env") == 0)
		return (print_strstr(g));
	else if (ft_strcmp(*args, "setenv") == 0)
		return (ft_parse_setenv(args));
	else if (ft_strcmp(*args, "cd") == 0)
		return (ft_chdir(args[1]));
	else if (ft_strcmp(*args, "unsetenv") == 0)
		return (ft_parse_unsetenv(args));
	else if (ft_strcmp(*args, "echo") == 0)
		return (ft_print_echo(args));
	else
		return (launch_execve(args, status));
}

static void	read_inp(void){
	char	*inp;
	char	**args;
	char	*inp_trim;
	int		ok;
	ok = 1;
	inp = NULL;
	while (ok){
        ft_putnbr(getpid());
		ft_putstr(">>> ");
		if (get_next_line(STDIN_FILENO, &inp) == -1)
			print_error("Error reading input.", 0);
		inp_trim = ft_strtrim(inp);
		ft_strdel(&inp);
		args = inp_handler(inp_trim);
		ft_strdel(&inp_trim);
		args_checker(args);
		ok = launch(args);
		if (args)
			ft_delstrstr(&args);
	}
}

int			main(int ac, char **av, char **env){
	(void)ac;
	(void)av;
	g = ft_dupstrstr(env);
	read_inp();
	ft_delstrstr(&g);
	return (0);
}


/* 
char		**inp_handler(char *input)
{
	char	**args;
	char	f;
	f = 0;
	if (!input || !*input)
		return (NULL);
	if (!(args = (char**)malloc(sizeof(char*) * (_POSIX_ARG_MAX)))){
		print_error("Memory Error", 0);
		return (NULL);
	}
	ft_inp_parser(args, input, &f);
	if (f){
		ft_putendl("Error: unmatched qoutes.");
		if (args && *args)
			ft_delstrstr(&args);
		return (NULL);
	}
	return (args);
}
 */

/* 
void	ft_delstrstr(char ***del_me){
	int i;

	i = 0;
	while ((*del_me)[i])
		free((*del_me)[i++]);
	free(*del_me);
}
 */


/* 
static int	launch(char **args){
	int		status;
	status = 1;
	if (!args || !*args || !**args)
		return (1);
	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	else if (ft_strcmp(*args, "env") == 0)
		return (print_strstr(g));
	else if (ft_strcmp(*args, "setenv") == 0)
		return (ft_parse_setenv(args));
	else if (ft_strcmp(*args, "cd") == 0)
		return (ft_chdir(args[1]));
	else if (ft_strcmp(*args, "unsetenv") == 0)
		return (ft_parse_unsetenv(args));
	else if (ft_strcmp(*args, "echo") == 0)
		return (ft_print_echo(args));
	else
		return (launch_execve(args, status));
}
 */
