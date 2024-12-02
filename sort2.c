#include <limits.h>
#include "push_swap.h"

int get_cost(int position, int total_len)
{
    if (position <= total_len / 2)
        return position;
    else
        return total_len - position;
}

int find_insert_position(t_stack *a, int value)
{
    t_stack *temp_a = a;
    int i = 0;

    if (a == NULL || a->len == 0)
        return 0;

    while (temp_a)
    {
        if (temp_a->content < value && (temp_a->next == NULL || temp_a->next->content > value))
            return i + 1;
        i++;
        temp_a = temp_a->next;
    }
    return 0;
}


int find_best_move(t_stack *b, t_stack *a)
{
    t_stack *temp_b = b;
    int min_cost = INT_MAX;
    int best_position = 0;
    int i = 0;

    while (temp_b)
    {
        int cost;
        if (a == NULL || a->len == 0) {
            cost = get_cost(i, b->len);
        } else {
            cost = get_cost(i, b->len) + get_cost(find_insert_position(a, temp_b->content), a->len);
        }

        if (cost < min_cost)
        {
            min_cost = cost;
            best_position = i;
        }
        temp_b = temp_b->next;
        i++;
    }
    return best_position;
}

void move_element_to_top(t_stack **stack, int position, char stack_name)
{
    if (*stack == NULL || position >= (*stack)->len)
        return;
    int len = (*stack)->len;
    if (position <= len / 2)
    {
        while (position-- > 0)
        {
            if (stack_name == 'a')
                ra(stack, 1);
            else
                rb(stack, 1);
        }
    }
    else
    {
        position = len - position;
        while (position-- > 0)
        {
            if (stack_name == 'a')
                rra(stack, 1);
            else
                rrb(stack, 1);
        }
    }
}

void rotate_a_to_bottom(t_stack **a)
{
    if (*a == NULL || (*a)->len <= 1)
        return;

    int min = (*a)->content;
    int position = 0;
    t_stack *temp = *a;
    int i = 0;

    while (temp)
    {
        if (temp->content < min)
        {
            min = temp->content;
            position = i;
        }
        temp = temp->next;
        i++;
    }

    move_element_to_top(a, position, 'a');
}

void sort_b_to_a(t_stack **a, t_stack **b)
{
    while (*b)
    {
        int best_move = find_best_move(*b, *a);
        move_element_to_top(b, best_move, 'b');
        int insert_position = find_insert_position(*a, (*b)->content);
        move_element_to_top(a, insert_position, 'a');
        pa(a, b);
    }
    rotate_a_to_bottom(a);
}