def join_two_halfs(first_half, second_half):
    i = 0
    j = 0
    res = []
    inversions = 0
    while 1: # doesn't feel very pythonic, what would be a better way to do that ?
        if i >= len(first_half):
            res += second_half[j:]
            break;
        elif j >= len(second_half):
            res += first_half[i:]
            break;
        elif first_half[i] <= second_half[j]:
            res.append(first_half[i])
            i += 1
        else:
            res.append(second_half[j])
            j += 1
            inversions += len(first_half[i:])
    return res, inversions

def count_inversions(l):
    """
    use a divide and conquer approch to calculate the number of inversions in a list
    [1, 2, 3, 4] got 0 inversions
    [3, 1, 2, 4] got 2 inversions (3-1) (3-2)
    [3, 2, 1, 4] got 3 inversions (3-2) (3-1) (2-1)
    """
    if len(l) <= 1:
        return l, 0
    # no optimization, list are duplicated
    middle = len(l) // 2

    first_half, inversions_first = count_inversions(list(l[:middle]))
    second_half, inversions_second = count_inversions(list(l[middle:]))
    res, inversions_inter = join_two_halfs(first_half, second_half)
    return res, inversions_first + inversions_second + inversions_inter

query = [input() for i in range(0,100000)]
a = [6,5,4,3,2,1]
print(count_inversions(query))