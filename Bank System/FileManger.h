#pragma once
#include <iostream>
#include <string>
#include "DataSourceInterface.h"
#include "FilesHandler.h"

class FileManger :public DataSourceInterface
{
private:
	static void DataSourceInterface::addClient(Client c) {
		FilesHandler::saveClient(c);
	}
	static void DataSourceInterface::addEmployee(Employee e) {
		FilesHandler::saveEmployee("Employee.txt", e);
	}
	static void DataSourceInterface::addAdmin(Admin a) {
		FilesHandler::saveEmployee("Admin.txt", a);
	}
	static void DataSourceInterface::getAllClients() {
		FilesHandler::getData("Clients.txt");
	}
	static void DataSourceInterface::getAllEmployees() {
		FilesHandler::getData("Employees.txt");
	}
	static void DataSourceInterface::getAllAdmins() {
		FilesHandler::getData("Admins.txt");
	}
	static void DataSourceInterface::removeAllClients() {
		FilesHandler::clearFile("Clients.txt");
	}
	static void DataSourceInterface::removeAllEmployees() {
		FilesHandler::clearFile("Employees.txt");
	}
	static void DataSourceInterface::removeAllAdmins() {
		FilesHandler::clearFile("Admins.txt");
	}
public:
	static void updateClientFile() {
		removeAllClients();
		for (clIt = allClients.begin(); clIt != allClients.end(); clIt++) {
			addClient(*clIt);
		}
	}
	static void updateEmployeeFile() {
		removeAllEmployees();
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			addEmployee(*eIt);
		}
	}
	static void updateAdminFile() {
		removeAllAdmins();
		for (aIt = allAdmins.begin(); aIt != allAdmins.end(); aIt++) {
			addAdmin(*aIt);
		}
	}

};

