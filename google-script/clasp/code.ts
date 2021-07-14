import {sumaPedorrona} from "./helpers"

type user = "Jorge" | "Patricio"

function onOpen(){
  SpreadsheetApp.getUi().createMenu("Menu Chido")
  .addItem("Hello Function", "hello")
}

function hello(){
  const ss = SpreadsheetApp.getActiveSpreadsheet()
  const sh = ss.getActiveSheet()

  let x: user = "Patricio"

  x="Patricio"
  
  const r = sh.getRange("A1")
  r.setValue(`Hola ${x}; ${sumaPedorrona(2, 3)}`)
}

