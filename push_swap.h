#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	stack_output(t_stack *stack);
t_stack	*stack_new(int value);
void	stack_append(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		is_sorted(t_stack *stack);

void	swap(t_stack *s);
void	push(t_stack *a, t_stack *b);
void	rotate(t_stack *s);
void	rrotate(t_stack *s);

void sa(t_stack *a, t_stack *b);
void sb(t_stack *a, t_stack *b);
void ss(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void ra(t_stack *a, t_stack *b);
void rb(t_stack *a, t_stack *b);
void rs(t_stack *a, t_stack *b);
void rra(t_stack *a, t_stack *b);
void rrb(t_stack *a, t_stack *b);
void rrs(t_stack *a, t_stack *b);

#endif