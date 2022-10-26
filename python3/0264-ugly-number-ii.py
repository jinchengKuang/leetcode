class Solution:
    def nthUglyNumber(self, n: int) -> int:
        p2 = p3 = p5 = 0
        product2 = product3 = product5 = 1
        res = []
        cur = 1
        while cur <= n:
            product_min = min(product2, product3, product5)
            res.append(product_min)
            cur += 1

            if product_min == product2:
                product2 = 2 * res[p2]
                p2 += 1
            if product_min == product3:
                product3 = 3 * res[p3]
                p3 += 1
            if product_min == product5:
                product5 = 5 * res[p5]
                p5 += 1

        return res[-1]


print(Solution().nthUglyNumber(10))
