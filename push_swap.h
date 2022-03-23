#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	int				index;
	int				rotations;
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
int		should_roll_up(t_stack *s, t_stack *target);
int		count_rolls(t_stack *s, t_stack *target);
t_stack	*locate_insertion_pos(t_stack *s, t_stack *target);
void	count_rotations(t_stack *a, t_stack *b);
t_stack	*locate_value(t_stack *stack, int value);
void	sort_stack(t_stack **a, t_stack **b);

void	store_rotations(int cmd);

int		is_value_valid(char *value, int *result, t_stack *stack);
t_stack	*read_stack(int len, char **values);

int		count_stack(t_stack *a);
t_stack	*find_max_element(t_stack *s);
t_stack	*find_min_element(t_stack *s);
void	normalize_values(t_stack *a);

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

# define CLEAN_ROTATIONS	0b1
# define ADD_RA				0b10
# define ADD_RRA			0b100
# define ADD_RB				0b1000
# define ADD_RRB			0b10000
# define MAKE_ROTATIONS		0b100000

void	sa(t_stack **a, t_stack **b);
void	sb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a, t_stack **b);
void	rb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, t_stack **b);
void	rrb(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif