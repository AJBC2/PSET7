-- MySQL dump 10.13  Distrib 5.5.41, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.41-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Portfolio`
--

DROP TABLE IF EXISTS `Portfolio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Portfolio` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(11) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`)
) ENGINE=InnoDB AUTO_INCREMENT=48 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Portfolio`
--

LOCK TABLES `Portfolio` WRITE;
/*!40000 ALTER TABLE `Portfolio` DISABLE KEYS */;
INSERT INTO `Portfolio` VALUES (1,1,'FB',1),(2,2,'AAPL',2),(3,3,'GOOG',3),(4,4,'YHOO',4),(5,5,'MCD',5),(6,6,'CPB',6),(7,7,'DUNKIN',7),(8,8,'PEP',8),(9,9,'KO',24),(10,10,'JNJ',10),(25,9,'MSFT',14),(31,11,'KO',1),(41,15,'KO',3),(47,11,'FB',10);
/*!40000 ALTER TABLE `Portfolio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `history`
--

DROP TABLE IF EXISTS `history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `history` (
  `user_id` int(11) unsigned NOT NULL,
  `trans` varchar(5) NOT NULL,
  `datetime` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `symbol` varchar(255) NOT NULL,
  `shares` int(11) unsigned NOT NULL,
  `price` decimal(65,2) unsigned NOT NULL,
  UNIQUE KEY `datetime` (`datetime`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `history`
--

LOCK TABLES `history` WRITE;
/*!40000 ALTER TABLE `history` DISABLE KEYS */;
INSERT INTO `history` VALUES (9,'BUY','2016-03-25 09:42:10','FB',2,357.42),(9,'BUY','2016-03-25 14:53:08','FB',5,113.05),(9,'SELL','2016-03-25 14:54:27','FB',0,113.05),(9,'BUY','2016-03-25 15:58:51','FB',2,113.05),(9,'SELL','2016-03-25 16:21:40','FB',0,113.05),(11,'BUY','2016-03-25 16:52:50','FB',3,113.05),(11,'SELL','2016-03-25 16:53:18','FB',0,113.05),(11,'BUY','2016-03-26 19:03:31','FB',2,113.05),(11,'SELL','2016-03-26 19:03:56','FB',0,113.05),(11,'BUY','2016-03-26 19:11:04','FB',2,113.05),(11,'BUY','2016-03-26 19:14:30','FB',2,113.05),(11,'BUY','2016-03-26 19:16:19','FB',2,113.05),(11,'SELL','2016-03-26 19:17:18','FB',0,113.05),(11,'BUY','2016-03-26 19:19:22','FB',1234,113.05),(11,'BUY','2016-03-26 19:19:52','KO',1,45.58),(11,'SELL','2016-03-26 19:20:19','FB',0,113.05),(11,'BUY','2016-03-26 19:20:28','FB',2,113.05),(11,'BUY','2016-03-27 00:21:03','AAPL',3,105.67),(11,'SELL','2016-03-27 00:22:42','PEP',0,100.68),(14,'BUY','2016-03-27 01:58:16','FB',346,113.05),(14,'SELL','2016-03-27 02:00:44','FB',0,113.05),(14,'BUY','2016-03-27 02:02:18','FB',123456,113.05),(14,'SELL','2016-03-27 02:06:05','FB',0,113.05),(14,'BUY','2016-03-27 02:17:42','FB',12345,113.05),(14,'BUY','2016-03-27 02:17:58','KO',3,45.58),(14,'SELL','2016-03-27 02:20:38','FB',0,113.05),(14,'SELL','2016-03-27 02:20:44','KO',0,45.58),(15,'BUY','2016-03-27 02:30:15','FB',5000,113.05),(15,'SELL','2016-03-27 02:30:52','FB',0,113.05),(15,'BUY','2016-03-27 02:38:10','FB',3,113.05),(15,'SELL','2016-03-27 02:41:31','FB',0,113.05),(15,'BUY','2016-03-27 02:55:21','FB',2,113.05),(15,'BUY','2016-03-27 02:59:30','KO',3,45.58),(15,'BUY','2016-03-27 03:15:28','FB',2,113.05),(15,'SELL','2016-03-27 03:16:06','FB',2,113.05),(15,'BUY','2016-03-27 03:28:11','AAPL',3,105.67),(15,'SELL','2016-03-27 03:28:18','AAPL',3,105.67),(11,'SELL','2016-03-27 05:40:59','AAPL',3,105.67),(11,'BUY','2016-03-29 02:00:31','FB',2,113.69),(11,'SELL','2016-03-29 02:01:29','FB',4,113.69),(11,'BUY','2016-03-29 02:02:31','FB',2,113.69),(11,'BUY','2016-03-29 02:10:39','FB',2,113.69),(11,'SELL','2016-03-29 02:11:43','FB',4,113.69),(17,'BUY','2016-03-29 02:20:51','SBUX',3,58.96),(17,'SELL','2016-03-29 02:21:20','SBUX',3,58.96),(11,'BUY','2016-03-29 02:48:55','FB',0,113.69),(11,'SELL','2016-03-29 02:53:02','FB',0,113.69),(11,'BUY','2016-03-29 02:53:10','FB',10,113.69);
/*!40000 ALTER TABLE `history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,4) unsigned NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.0000),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.0000),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.0000),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.0000),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.0000),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.0000),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.0000),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.0000),(9,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',10121.3250),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.0000),(11,'ajbc','$2y$10$VKlx9Dv0kJv4vcI8T5GcJuwfbgqfKw83evvPuLvoURUOAIyX0lYHm',140784.4000),(12,'juandi','$1$WADZMvjP$6VP.3NQjjeCWb0IObqbUy/',10000.0000),(13,'juandi2','$2y$10$fbDXXWYpNsZslCznCbW1yupu6OK9z24NzcnRdl4EI.bt.37blqEm.',10000.0000),(14,'toz','$2y$10$9Eknw5j8YOD0lKEe8cNyOO1u7V5pJMnsYnuD4Mp5s2mcnN9MK4IEO',10000.0000),(15,'tz','$2y$10$VrpuYTuhMqWBduQZ2b2Gj.85eIcPqpWcBujD942BI136MaMr/96xm',9863.2600),(17,'ajbc2','$2y$10$D1tqut1Qda9tbPG2rSAake63zUadRHmIQqpyeG.wPjTOR7c3/Gnbe',10000.0000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-03-29  2:55:26
