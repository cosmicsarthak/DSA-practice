def find_combinations(items, limit, combination=[]):
    # Base case: if no more items are left, return the current combination
    if not items:
        return [combination]

    # Recursive case: try adding each item to the combination and recursively find all possible combinations
    combinations = []
    for item in items:
        if sum(combination + [item]) <= limit:
            # Add the item to the combination and find all possible combinations of the remaining items
            combinations += find_combinations(items[:],
                                              limit, combination + [item])

    return combinations


# Test the function
items = [1, 2, 3, 4]
limit = 10
combinations = find_combinations(items, limit)
print(combinations)
