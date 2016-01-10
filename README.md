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

```
 CREATE TABLE `recode` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `no` varchar(32) NOT NULL DEFAULT '' COMMENT '顾客购物时的号码，需要与日期结合',
  `CID` int(11) NOT NULL COMMENT '商品ID',
  `num` tinyint(4) DEFAULT '0' COMMENT '购买商品的数量',
  `consume_time` int(11) DEFAULT NULL COMMENT '消费的时间',
  `remarks` varchar(128) DEFAULT NULL COMMENT '顾客消费的备注信息',
  PRIMARY KEY (`ID`),
  KEY `CID` (`CID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='顾客消费记录表';
```

数据格式如图
查询语句为：select * from recode where no = '20160110_A001';
```
+----+---------------+-------+------+--------------+---------+
| ID | no            | CID   | num  | consume_time | remarks |
+----+---------------+-------+------+--------------+---------+
|  1 | 20160110_A001 | 20001 |    2 |   1452390564 | 无      |
|  2 | 20160110_A001 | 20002 |    1 |   1452390564 | 无      |
+----+---------------+-------+------+--------------+---------+
```