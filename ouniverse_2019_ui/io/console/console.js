class IO_CONSOLE
{
	constructor()
	{
		//this.open()
		this.console
		this.output
		this.log = []
		engine.on('console_open', this.open)
		engine.on('console_close', this.close)

	}

	open()
	{
		var console = document.createElement('div')
		console.style.position = "absolute"
		console.style.bottom = "0"
		console.style.backgroundColor = "red"
		console
		console.style.opacity = "0.9"
		console.style.width="100%"
		console.style.height="0px"
		document.body.appendChild(console)

		anime({
		  targets:console,
		  height: "50px",
		  duration: 100,
		  easing: 'linear'
		});

		this.console = console
		engine.call("console_onOpen")
	}


	close()
	{
		console.log("DID IT?")
		this.console.parentNode.removeChild(this.console);
		engine.call("console_onClose")

	}
}