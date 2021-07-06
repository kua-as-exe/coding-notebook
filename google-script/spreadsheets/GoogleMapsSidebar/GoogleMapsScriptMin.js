
function ShowGoogleMaps(){
  let html = HtmlService.createHtmlOutput();
  html.setContent(`
  <!DOCTYPE html>
  <html>
    <head>
      <base target="_top">
      <style>
        html{ height: 100%; }
        body{ height: 100%; display: flex; flex-direction: column; }
        #map { width: 100%; height: 100%; }
      </style>
    </head>
    <body>
      <iframe
        id="map"
        style="border:0"
        loading="lazy"
        allowfullscreen
      > </iframe>

      <script>
        const API_KEY = "AIzaSyDAfVdMDXBc1CFaC7XRe0cOmyeeSWqsRlk"
        const refreshDelay = 1 // seconds
        function srcUrl (coords) {
          return "https://www.google.com/maps/embed/v1/place?key="+API_KEY+"&q="+encodeURIComponent(coords)
        }
        
        let temp_coords = null;
        let interval = null;

        function coordsHandler (coords){
          if(coords != temp_coords && coords != ""){
            console.log(coords)
            temp_coords = coords
            document.getElementById('map').src = srcUrl(coords)
          }
        }

        function refreshHandler (){
          google.script.run.withSuccessHandler( coordsHandler ).getCords()
        }

        document.addEventListener('DOMContentLoaded', () => {
          console.log("Contend loaded")
          interval = setInterval( refreshHandler, refreshDelay*1000 )
        });
        
      </script>
    </body>
  </html>
  `)
  SpreadsheetApp.getUi().showSidebar(html)
}

function getCords(){
  let cell = SpreadsheetApp.getActiveSpreadsheet().getActiveCell()
  let row = cell.getRow()
  let coords = SpreadsheetApp.getActiveSpreadsheet().getSheetByName("coords").getRange(row, 1).getValue();
  Logger.log(coords)
  return coords;
}
