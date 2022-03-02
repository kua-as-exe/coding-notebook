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
