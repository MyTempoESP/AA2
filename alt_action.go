package main

import (
	mysql "github.com/mytempoesp/mysql-easy"
)

func RestartComputer() (err error) {

	db, err := mysql.ConfiguraDB()

	if err != nil {

		return
	}

	_, err = db.Exec("UPDATE equipamento SET action = 1")

	defer db.Close()

	return
}
