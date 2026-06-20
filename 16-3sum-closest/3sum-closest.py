class Solution:
    def threeSumClosest(self, nums, target):
        nums.sort()
        closest = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1

            while left < right:
                current_sum = nums[i] + nums[left] + nums[right]

                # Update closest sum if current is nearer to target
                if abs(current_sum - target) < abs(closest - target):
                    closest = current_sum

                if current_sum < target:
                    left += 1
                elif current_sum > target:
                    right -= 1
                else:
                    return current_sum  # Exact match

        return closest