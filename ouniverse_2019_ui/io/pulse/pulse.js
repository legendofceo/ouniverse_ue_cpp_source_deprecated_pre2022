class IO_PULSE
{
	constructor()
	{
		//this.open()
		this.c
		this.output
		this.log = []
		engine.on('pulse_start', this.start)
		engine.on('pulse_end', this.end)

	}

	start()
	{
		console.log("WE ARE STARTED          )))))))))))))))))))))))))))))))))))))))))))")
		var div = document.createElement('div')
		document.body.appendChild(div)
		div.classList.add("pulse_grid")

		for(var i=0;i<25;i++)
		{
			var mini = document.createElement('div')
			div.appendChild(mini)
			mini.classList.add("pulse_mini")
		}


		anime({
  targets: '.pulse_grid .pulse_mini',
  scale: [
    {value: 0.0, easing: 'easeOutSine', duration: 500},
    {value: 1, easing: 'easeInOutQuad', duration: 1200}
  ],
  delay: anime.stagger(200, {grid: [5, 5], from: 'center'})
});

		this.c = div
		
	}


	end()
	{
		console.log("DID IT?")
		this.c.parentNode.removeChild(this.c);
		engine.call("pulse_onEnd")

	}
}