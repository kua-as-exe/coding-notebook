> Doc will be here if needed

## Broadly...

It's a recursion to search through `_pageData`, a Server Side Loaded data about the routes and points (i guess). A quite messy array.

This recursion executes `filter` function for every element. If the response is true, it runs `callback` with the current item as argument, for you to do whatever u want with that item.

In my case, `filter` looks for a regex that match a bit with coordinates format, and in `callback` its stored as an array of list for the two coords (lat and long). Result will be shown in a window prompt to be copied with Ctrl+C

```js

F = (item, filter, callback, parent) => {
    if( item === null || item === undefined ) return 
    if( filter && typeof(filter) === 'function' && filter(item) )
        callback(item, parent);
    
    if( typeof(item) === 'object' )
        if( item.hasOwnProperty('length') )
            for( let child of item )
                F(child, filter, callback, item)
}
list = []; temp = []
data = JSON.parse(_pageData)
filter = (i) => {
     if( typeof(i) === 'number') 
        if( String(i).match(/-?(\d{2,3})\.(\d+)/) )
         return true      
}
callback = (i, p) => {
    //console.log(i)
    temp.push(i)
    if( temp.length == 2 ){
        list.push(temp)
        temp = []
    }
}
F(data, filter, callback)
window.prompt("", list.map(x => x.join(",") ).join("\n"))
```
