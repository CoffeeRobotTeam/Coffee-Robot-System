# storage分支

数据存储采用MYSQL数据库，储存项目中的支付记录和商品信息

商品信息表结构
```
CREATE TABLE `commodity` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL DEFAULT '' COMMENT '商品名称',
  `price` int(11) NOT NULL DEFAULT '0' COMMENT '商品价格价格X100',
  `create_at` int(11) unsigned DEFAULT NULL,
  `update_at` int(11) unsigned DEFAULT NULL,
  `description` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=20004 DEFAULT CHARSET=utf8;

```
数据格式如图,可以修改
```
+-------+------------+-------+------------+------------+-------------+
| ID    | name       | price | create_at  | update_at  | description |
+-------+------------+-------+------------+------------+-------------+
| 20003 | 小杯纯咖啡 |  2000 | 1452048897 | 1452048897 | 无优惠      |
+-------+------------+-------+------------+------------+-------------+
```