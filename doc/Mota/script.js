function veTron() {
	var c = document.createElementNS("http://www.w3.org/2000/svg", 'circle');
	c.setAttribute('cx', Math.floor(Math.random()*500));
	c.setAttribute('cy', Math.floor(Math.random()*500));
	c.setAttribute('r','10');
	c.setAttribute('fill', 'red');
	c.setAttribute('fill-opacity', '1');

	document.getElementById('svg').appendChild(c);
}

function toiLai() {
	var b = document.createElementNS("http://www.w3.org/2000/svg",'rect');
	b.setAttribute('width','100%');
	b.setAttribute('height','100%');
	b.setAttribute('fill','black');
	b.setAttribute('fill-opacity','0.05');

	document.getElementById('svg').appendChild(b);
}

function ve() {
setTimeout(function() {
	veTron();
	toiLai();
}, 500);
}

document.getElementById('svg').onmousemove = function() {
	ve();
};