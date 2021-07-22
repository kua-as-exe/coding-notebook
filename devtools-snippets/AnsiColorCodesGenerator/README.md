# ANSI Color codes generator

If you want to manage terminal colors by your own (without libraries like [chalk](https://www.npmjs.com/package/chalk) in nodejs or [colored](https://pypi.org/project/colored/) in python), or you didn't find any library to do it (as mi with cpp), this script can generate a list of colors to define in your preferred syntax language.

You can find more information about ANSI color codes in [Build your own Command Line with ANSI escape codes](https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html#colors)  

I nedded this in cpp, but i'm too lazy to write it by hand in 2 minutes. So I spent half an hour to do this script that do it automatically for you :)

## Usage

Copy the following code to your web browser console

```js
// Terminal colors ANSI escape codes generator

// Reference: ~ https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html#colors

let rawColors =`
Black: \u001b[30m
Red: \u001b[31m
Green: \u001b[32m
Yellow: \u001b[33m
Blue: \u001b[34m
Magenta: \u001b[35m
Cyan: \u001b[36m
White: \u001b[37m
Reset: \u001b[0m

Bright Black: \u001b[30;1m
Bright Red: \u001b[31;1m
Bright Green: \u001b[32;1m
Bright Yellow: \u001b[33;1m
Bright Blue: \u001b[34;1m
Bright Magenta: \u001b[35;1m
Bright Cyan: \u001b[36;1m
Bright White: \u001b[37;1m

Background Black: \u001b[40m
Background Red: \u001b[41m
Background Green: \u001b[42m
Background Yellow: \u001b[43m
Background Blue: \u001b[44m
Background Magenta: \u001b[45m
Background Cyan: \u001b[46m
Background White: \u001b[47m

Background Bright Black: \u001b[40;1m
Background Bright Red: \u001b[41;1m
Background Bright Green: \u001b[42;1m
Background Bright Yellow: \u001b[43;1m
Background Bright Blue: \u001b[44;1m
Background Bright Magenta: \u001b[45;1m
Background Bright Cyan: \u001b[46;1m
Background Bright White: \u001b[47;1m

Reset: \u001b[0m
Bold: \u001b[1m
Underline: \u001b[4m
Reversed: \u001b[7m
`.split("\n");
let colors = rawColors.filter(t => !!t).map( t => {
    let [fullName, code] = t.split(":")
    let name = String(fullName);
    name = name.replace("Background", "BG");
    name = name.replace("Bright", "BRI");
    name = name.split(" ")
        .map( sub => sub.length > 3? sub.slice(0, 3): sub )
        .map( sub => String(sub).toUpperCase() )
        .join("_");

    code = code.trim();
    return {name, code, fullName};
});
console.log(colors)

let getColors = ( parseFunc = (_name="", _code="") =>{} ) => {
    let text = colors.map( 
        ({name, code}) => parseFunc(name, code)
    ).join("\n");

    // Prevent devtools terminal to interpret as colors
    let escape = (s = "") => s.replace(/[\\[\]]/g, '\\$&');
    console.log(escape(text));

    if(copy) {
        copy(text); // handle copy on devtools
        console.log("Text copied to clipboard");
    }
}

```

## Generate the code

Use the function `getColors` and send a function that get 2 arguments: `name` and `code`. `name` is the color's prefix name (for example, to be stored in a variable), and `code` is the string color code to be used as an assigment. You must return a string

Example:

```js
// Parse to c++ "#define" format
getColors( (name, code) => {
    return `#define ${name} "${code}"`
})
```

```js
// Parse to c++ "string x = "" " format
getColors( (name, code) => {
    return `string ${name} = "${code}"`
})
```


```js
// Parse to javascript " const x = "" " format
getColors( (name, code) => {
    return `const ${name} = "${code}"`
})
```

```js
// Parse to javascript " let x = "" " format
getColors( (name, code) => {
    return `let ${name} = "${code}"`
})
```


```js
// Parse to python " x = "" " format
getColors( (name, code) => {
    return `${name} = "${code}"`
})
```
