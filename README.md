# Coffee Shop Management Database Application

*Project Overview:*
The Coffee Shop Management System is a comprehensive software solution designed to streamline and enhance the operations of a coffee shop. 
This system leverages C++ programming and Oracle Database to manage various aspects of the coffee shop, including order processing, customer information, and inventory management.

# *Key Features:*

## Order Processing and Reporting:
The system facilitates the generation of detailed reports on all orders placed, providing insights into order numbers, associated tables, product names, quantities, and order dates.
An additional report highlights outstanding orders, showcasing order numbers, corresponding tables, customer names, outstanding amounts, and order dates.

## Inventory Management:
The system effectively manages inventory by providing a report on product availability. 
This report includes product IDs, names, associated categories, unit prices, and availability statuses.
Products are categorized into a variety of types, such as regular beverages, soft drinks, pastries, and more.

## Database Interaction with Oracle:
Utilizing Oracle OCCI, the system establishes a secure and efficient connection with the Oracle Database (myoracle12c.senecacollege.ca:1521/oracle12c).
SQL queries are employed to retrieve and process data, ensuring accurate and timely reporting.

## Database Schema:
The system is backed by a robust database schema consisting of the following tables:

CATEGORY: Stores information about product categories.

PRODUCT: Manages details about individual products, including category associations.

TABLEDETAILS: Records details about tables within the coffee shop.

CUSTOMER: Contains customer information such as customer ID, name, and phone number.

NEWORDERDETAILS: Captures data related to new orders, including customer and table associations.

ORDERITEM: Manages details about items within each order, including product and order associations.

PAYMENTMETHOD: Stores information about various payment methods accepted.

PAYMENT: Records details of payments made for orders, including order and payment method associations.

## Sample Data:
The system is populated with sample data, including product categories, products, table details, customer information, new order details, order items, payment methods, and payments.

## Technologies Used:

*Programming Language:*
- C++

*Database:*
- Oracle Database with Oracle OCCI

*Tools and Libraries:*
- Oracle OCCI, SQL*Plus

## Conclusion:

The Coffee Shop Management System serves as an efficient tool for coffee shop owners and staff to manage orders, track inventory, and ensure smooth operations. It demonstrates proficiency in database management, C++ programming, and Oracle OCCI, providing a solid foundation for further enhancements and customization.
