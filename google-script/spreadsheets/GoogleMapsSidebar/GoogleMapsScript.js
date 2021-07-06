
function ShowGoogleMaps(){
  var html = HtmlService.createHtmlOutputFromFile('GoogleMaps').setTitle('Google Maps')
  SpreadsheetApp.getUi().showSidebar(html)
}

function getCords(){
  let cell = SpreadsheetApp.getActiveSpreadsheet().getActiveCell()
  let row = cell.getRow()
  let coords = SpreadsheetApp.getActiveSpreadsheet().getSheetByName("coords").getRange(row, 1).getValue();
  Logger.log(coords)
  return coords;
}
