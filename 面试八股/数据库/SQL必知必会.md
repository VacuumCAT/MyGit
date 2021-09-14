 ### 第二课 检索数据  
 * 检索单个列  
  select prod_name
  from Products;
* 检索多个列  
  select prod_id,prod_name,prod_price
  from Products;
* 检索所有列
  select *
  from Products;
* 检索不同的值
  select vend_id
  from Products;
  select distinct vend_id 
  from Products;
* 限制结果  
  select prod_name
  from Products
  limit 5;
  select prod_name
  from Products
  limit 5 offset 5;
  这里的offest是从哪里开始，而第一个被检索的行是第0行
* 挑战题


### 第3课 排序检索数据  
* 排序数据  
* 按多个列排序
* 按列位置排序
* 指定排序方向

### 第4课 过滤数据
### 第5课 高级数据过滤
and\or操作符，圆括号改变求值顺序，in操作符（替代or）、not操作符
* 挑战题
1. select vend_name
   from Vendors
   where vend_country='USA'
   and vend_state='CA';

### 第6课 使用通配符进行过滤
%、_、[]

### 第7课 创建计算字段