
/*
* 上升的温度，输出当天温度较前一天有上升的温度
* 使用DATEDIFF来判断是不是前一天（即两天相隔时间为 1 ）
* 不要用date = date - 1； 执行结果不对
*/

select w1.id as Id
from Weather as w1
where w1.temperature > (
    select w2.temperature from Weather as w2
    where DATEDIFF(w1.recordDate, w2.recordDate) = 1
    )