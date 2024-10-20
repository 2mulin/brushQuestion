#!/bin/bash

# 1. 首先使用tr 替换文本中的空格为 换行符
# 2. 对所有单词排序
# 3. 去重统计次数
# 4. 根据单词出现次数进行降序排序
# 5. 格式化输出, 单词在前, 次数在后
cat words.txt| tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2, $1}'
