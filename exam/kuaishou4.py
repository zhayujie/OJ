import sys

# 80.00% accept

def find_seq_num():
    max_count = 0
    n = sys.stdin.readline()
    nums = sys.stdin.readline().strip().split()

    if len(nums) == 0 or len(nums) == 1:
        print(len(nums))
        return

    for i in range(0, len(nums)):
        nums[i] = int(nums[i])
    list.sort(nums)

    i = 0
    j = 0
    k = nums[1] - nums[0]
    while j < len(nums) - 1:
        if nums[j+1] - nums[j] != k:
            i = j
            j += 1
            k = nums[j] - nums[i]
        else:
            j += 1
            count = j - i + 1
            print('j: ' + str(j) + ' i: ' + str(i))
            max_count = max(max_count, count)
    print(max_count)


if __name__ == '__main__':
    find_seq_num()
