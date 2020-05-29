#ifndef MSH_H
# define MSH_H
# include "../libft/libft.h"
# include <dirent.h>
# include <limits.h>
# include <sys/wait.h>
# define S_ON	01
# define S_VAL	02

char		**g;
void		ft_delstrstr(char ***del_me);
void	    print_error(char *err, int f);
size_t		ft_strstrlen(char **ss);
char		*ft_find_param(char **env, char *env_var, char *arg, int flag);
void		ft_setstrstr(char *var, char *value, size_t varlen, size_t vallen);
char		**ft_strstr_remalloc(char **arr, char *str);
char		**ft_dupstrstr(char **arr);
char		**inp_handler(char *input);
int			print_strstr(char **ss);
int			ft_parse_setenv(char **args);
int			ft_chdir(char *path);
int			ft_permission_check_f(char *str);
int			ft_permission_check(char *str);
void		ft_unsetstrstr(char *varname);
int			ft_print_echo(char **args);
void		expander(char **args);
void	    print_err_delstrstr(char *err, char ***arrdel, int f);
int			ft_parse_unsetenv(char **args);
char    	*ft_strjoin_del(char *s1, char *s2);
int		    space_checker(int c);

#endif
