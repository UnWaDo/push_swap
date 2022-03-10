#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Converts value located in `str` to long
// For now does not work with bases other than 10
// `endptr` is set to the last valid character similar
// to libc `strtol` function
long	ft_strtol(const char *str, char **endptr, int base);

void	stack_output(t_stack *stack);
t_stack	*stack_new(int value);
void	stack_append(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		is_sorted(t_stack *stack);

// Swaps the first two elements of stack `s`
// Does nothing if stack is empty
// or has only one element
void	swap(t_stack **s);
// Takes the first element of stack `a`
// and puts it at the top of `b`
// Does nothing if `a` is empty
void	push(t_stack **a, t_stack **b);
// Shifts up all elements of the stack
// `s` by one. The first element becomes
// the last one
void	rotate(t_stack **s);
// Shifts down all elements of the stack
// `s` by one. The last element becomes
// the first one
void	rrotate(t_stack **s);

void sa(t_stack **a, t_stack **b);
void sb(t_stack **a, t_stack **b);
void ss(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void ra(t_stack **a, t_stack **b);
void rb(t_stack **a, t_stack **b);
void rs(t_stack **a, t_stack **b);
void rra(t_stack **a, t_stack **b);
void rrb(t_stack **a, t_stack **b);
void rrs(t_stack **a, t_stack **b);

#endif