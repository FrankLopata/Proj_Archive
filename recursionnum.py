def find_max(nums: list[int]) -> int:
    '''
    Finds the maximum value in the given list of integers,
    or None if the list is empty
    '''
    if len(nums) == 0:
        return None
    largest = nums[0]
    if len(nums)>1:
        if largest >= nums[1]:
            nums.remove(nums[1])
            find_max(nums)
        else:
            nums.remove(nums[0])
            find_max(nums)

    return largest