# Wakatime Data Downloader

Download last 14 days data from your wakatime account in JSON format

Get daily summaries of:

- Categories
- Dependencies
- Editors
- Languages
- Machines
- Operative systems
- Projects
- Total

## Usage

Just copy the following snippet in your browser console in devtools

```js
// By: Jorge Arreola
// ~ https://github.com/JorgeArreolaS/coding-notebook/tree/main/devtools-snippets/wakatimeDownloader

( async () => {
    let parseDate = (d) => `${d.getFullYear()}-${d.getMonth()+1}-${d.getDate()}`
    let end = new Date()
    let start = new Date(end)
    start.setDate( end.getDate()-14)
    let url = `https://wakatime.com/api/v1/users/current/summaries?start=${parseDate(start)}&end=${parseDate(end)}`
    let data = {}
    
    let res = await fetch(url)
    data = await res.json()
    console.log(data)

    let filename = `wakatime_${parseDate(start)}_${parseDate(end)}.json`
    data = JSON.stringify(data, undefined, 4)

    // inspired by: ~ https://bgrins.github.io/devtools-snippets/#console-save
    var blob = new Blob([data], {type: 'text/json'}),
        e    = document.createEvent('MouseEvents'),
        a    = document.createElement('a')

    a.download = filename
    a.href = window.URL.createObjectURL(blob)
    a.dataset.downloadurl =  ['text/json', a.download, a.href].join(':')
    e.initMouseEvent('click', true, false, window, 0, 0, 0, 0, 0, false, false, false, false, 0, null)
    a.dispatchEvent(e)
})()
```

Choose your destination folder to download, download, and done.

### Example

<img src="https://i.imgur.com/RZR51oM.png"/>

## Notes

- You have to be logged in with your account
- The script dont handle conections or date errors, hope you could solve by yourself if something happends
