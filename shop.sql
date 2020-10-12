-- MySQL dump 10.17  Distrib 10.3.23-MariaDB, for debian-linux-gnueabihf (armv7l)
--
-- Host: localhost    Database: Shop
-- ------------------------------------------------------
-- Server version	10.3.23-MariaDB-0+deb10u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Customer_List`
--

DROP TABLE IF EXISTS `Customer_List`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Customer_List` (
  `Customer_ID` int(11) NOT NULL,
  `First_name` varchar(100) DEFAULT NULL,
  `Middle_Name` varchar(100) DEFAULT NULL,
  `Last_Name` varchar(100) DEFAULT NULL,
  `Phone_Number` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`Customer_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Customer_List`
--

LOCK TABLES `Customer_List` WRITE;
/*!40000 ALTER TABLE `Customer_List` DISABLE KEYS */;
/*!40000 ALTER TABLE `Customer_List` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Customer_Order`
--

DROP TABLE IF EXISTS `Customer_Order`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Customer_Order` (
  `Order_ID` int(11) NOT NULL,
  `Customer_ID` int(11) DEFAULT NULL,
  `Item_ID` int(11) DEFAULT NULL,
  `Quantity` double DEFAULT NULL,
  `Unit` varchar(20) DEFAULT NULL,
  `Item_Total_price` double DEFAULT NULL,
  PRIMARY KEY (`Order_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Customer_Order`
--

LOCK TABLES `Customer_Order` WRITE;
/*!40000 ALTER TABLE `Customer_Order` DISABLE KEYS */;
/*!40000 ALTER TABLE `Customer_Order` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Item`
--

DROP TABLE IF EXISTS `Item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Item` (
  `Item_ID` int(11) NOT NULL,
  `Item_Name` varchar(50) DEFAULT NULL,
  `Quantity` double DEFAULT NULL,
  `Unit` varchar(20) DEFAULT NULL,
  `Category` varchar(100) DEFAULT NULL,
  `Item_Price` double DEFAULT NULL,
  PRIMARY KEY (`Item_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Item`
--

LOCK TABLES `Item` WRITE;
/*!40000 ALTER TABLE `Item` DISABLE KEYS */;
INSERT INTO `Item` VALUES (1,'Dress',0,NULL,'Others',200),(2,'Hand Watch',99,NULL,'Technology',800),(3,'Smart Phone',76,NULL,'Technology',8000),(4,'TV',150,NULL,'Entertainment',10000),(5,'Washing Machine',49,NULL,'Technology',20000),(6,'Text Book',196,NULL,'Education',60),(7,'Copies',599,NULL,'Education',20),(8,'Pen and Pencil',198,NULL,'Education',20),(9,'Potatoes',97,'kg','Food',30),(10,'Mustard Oil',199,'litres','Food',124);
/*!40000 ALTER TABLE `Item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Vendor_List`
--

DROP TABLE IF EXISTS `Vendor_List`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Vendor_List` (
  `Vendor_ID` int(11) NOT NULL,
  `Vendor_Name` varchar(150) DEFAULT NULL,
  `Vendor_Username` varchar(50) DEFAULT NULL,
  `Vendor_Email` varchar(60) DEFAULT NULL,
  `Vendor_Password` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`Vendor_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Vendor_List`
--

LOCK TABLES `Vendor_List` WRITE;
/*!40000 ALTER TABLE `Vendor_List` DISABLE KEYS */;
/*!40000 ALTER TABLE `Vendor_List` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-10-12  9:14:06
