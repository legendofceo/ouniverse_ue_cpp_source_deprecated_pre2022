class UO_USER
{
	constructor(newUser)
	{
			this.id = newUser.ID
			this.sn = newUser.SN
	}
}

class IO_USER
{

	constructor()
	{	
		this.users = []
		console.log("IO User:Active")
		engine.on('user_sendUserData', this.registerUser.bind(this))
		engine.on('user_modeSelect', this.modeSelect.bind(this))
	}

	start()
	{
		
	}

	modeSelect()
	{
		for(var i=0;i<this.users.length;i++)
		{
			console.log(this.users[i].id)
			console.log(this.users[i].sn)
		}
	}

	registerUser(newUser)
	{
		this.users.push(new UO_USER(newUser))
	}

	end()
	{

	}
}