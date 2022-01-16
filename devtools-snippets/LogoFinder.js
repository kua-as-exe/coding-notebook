const findLogo = async query => {
  const res = await fetch(
    'https://worldvectorlogo.com/search/' + encodeURIComponent(query),
  );
  const html = await res.text();
  const matchs = html.matchAll(
    new RegExp('((?=https://cdn.worldvectorlogo.com/logos).+?(=?.svg))', 'g'),
  );
  const icons = Array.from(matchs).map(r => r[0]);
  console.log(icons.slice(0, 5).join('\n'));
  return icons;
};

const run = query => {
  const copy = e => {
    console.log(e.target.src);
    navigator.clipboard.writeText(e.target.src);
  };

  const addImg = src => {
    const img = document.createElement('img');
    img.src = src;
    img.addEventListener('click', copy);
    document.body.append(img);
  };

  document.body.innerHTML = `<style> img { width: 100px; margin: 5px;} </style>`;
  findLogo(query).then(logos => logos.forEach(addImg));
};
