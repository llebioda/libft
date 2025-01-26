/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:18:12 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/26 17:11:21 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(char c);
int		is_empty_str(char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);
int		ft_atoi_valid(const char *nptr);
int		ft_atoi_safe(const char *nptr, int error_ret_val);
long	ft_atol(const char *nptr);
int		ft_atol_valid(const char *nptr);
long	ft_atol_safe(const char *nptr, long error_ret_val);
char	*ft_itoa(int n);

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp_alpha(const char *s1, const char *s2);
int		ft_strncmp_alpha(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
size_t	ft_strlcat(char *dst, const char *src, size_t siz);
char	*ft_strrev(char *str);

int		ft_strcontains(const char *str, char c);
int		ft_strstartwith(const char *str, const char *start);
int		ft_strendwith(const char *str, const char *end);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin3(const char *s1, const char *s2, const char *s3);
char	*ft_strjoin_all(const char **tab, const char *sep);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoin3_free(char *s1, char *s2, char *s3);

char	*ft_strdup(const char *src);
char	*ft_strndup(const char *src, unsigned int n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strremove(const char *str, const char *set);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_strtrim_space(const char *str);
char	**ft_split(const char *s, const char *set);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_sort_str(char **tab);
void	ft_custom_sort_str(char **tab, int (*cmp)(const char *, const char *));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

void	ft_swap(int *a, int *b);
int		ft_abs(int value);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_clamp(int value, int min, int max);

void	ft_swap_db(double *a, double *b);
double	ft_abs_db(double value);
double	ft_min_db(double a, double b);
double	ft_max_db(double a, double b);
double	ft_clamp_db(double value, double min, double max);

int		*ft_range(int min, int max);
int		ft_factorial(int nb);
int		ft_power(int nb, int power);

void	ft_free_tab(char ***tab);
char	**ft_dup_char_array(char **array);
char	**ft_realloc_char_tab(char **tab, size_t new_size);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	*ft_lstpop(t_list **lst, int index);
t_list	*ft_lstinsert(t_list **lst, int index, void *content);

t_list	*ft_lstfirst_occ(t_list *lst, int (*f)(void *, void *), void *params);
int		ft_lstfirst_occ_index(t_list *lst,
			int (*f)(void *, void *), void *params);

#endif
