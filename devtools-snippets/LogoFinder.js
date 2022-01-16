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
