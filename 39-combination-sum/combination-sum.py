class Solution:
    def combinationSum(self, candidates, target):
        result = []

        def backtrack(index, target, path):
            if target == 0:
                result.append(path[:])
                return

            if index == len(candidates) or target < 0:
                return

            path.append(candidates[index])
            backtrack(index, target - candidates[index], path)
            path.pop()

            backtrack(index + 1, target, path)

        backtrack(0, target, [])
        return result