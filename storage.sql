 CREATE TABLE `commodity` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL DEFAULT '' COMMENT '商品名称',
  `price` int(11) NOT NULL DEFAULT '0' COMMENT '商品价格价格X100',
  `create_at` int(11) unsigned DEFAULT NULL,
  `update_at` int(11) unsigned DEFAULT NULL,
  `description` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=20004 DEFAULT CHARSET=utf8;