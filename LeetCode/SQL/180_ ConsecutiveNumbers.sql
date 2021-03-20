/**************************************
求出表中连续出现的数字
表名 : Logs
直接对一个table做自联结两次
再加上Num相等, 并且最终答案去重就可以了
**************************************/

-- 还要记得使用distinct去重
SELECT distinct l1.Num as ConsecutiveNums
FROM
    Logs as l1,             -- 自联结自己
    Logs as l2,
    Logs as l3
WHERE
    l1.Id = l2.Id - 1
    AND l2.Id = l3.Id - 1   -- 连续的记录
    AND l1.Num = l2.Num     -- Num相等
    AND l2.Num = l3.Num

