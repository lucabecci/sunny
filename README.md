<h1 align="center">Sunny Database</h1>

> Sunny is `fast`, `easy` and`key-value` in memory database. 

## ✨ Demo

<p align="center">
  <img width="700" align="center" src="https://s10.gifyu.com/images/Grabacion-de-pantalla-2022-01-06-a-la_s_-01.57.30.gif" alt="demo"/>
</p>

## ❗ Important
Sunny takes care of removing the least used keys in the database in order to get a quick response at all times.
## 🔧 Installation 

Make sure you have [g++](https://www.mingw-w64.org/) for this project.

### Manual compilation
Just run the following command at the root of your project to compile the code:

For the Sunny CLI:

```bash
g++ ./runtime/client_runtime.cpp -o client && ./client.out 
```

For the Sunny server:

```bash
g++ ./runtime/server_runtime.cpp -o server && ./server.out 
```
### Makefile
You can create the binaries through a makefile and then run them through the console, they will be in the "bin" folder:
```bash
make
```
After this you could run the client or the server by:
```bash
##the client
./bin/client

##the server
./bin/server
```

## 🚀 Usage
You can see the manual in the CLI  with the `help` command.

Principal commands:
- <span style="color:cyan">put</span> key value - This command will add up or update one key in the database.
- <span style="color:cyan">get</span> key - This command will find a key in the database.

## 🤝 Contributing

Contributions, issues and feature requests are welcome.<br />
Feel free to check [issues page](https://github.com/lucabecci/sunny/issues) if you want to contribute.<br />
[Check the contributing guide](./CONTRIBUTING.md).<br />

## Author

👤 **Luca Becci**

- Linkedin: [Luca Becci](https://www.linkedin.com/in/luca-becci-b8044b198/)
- Github: [@lucabecci](https://github.com/lucabecci)

## Show your support

Please ⭐️ this repository if this project helped you!

## 📝 License

Copyright © 2022 [Luca Becci](https://github.com/lucabecci).<br />
This project is [MIT](https://github.com/lucabecci/sunny/blob/master/LICENSE) licensed.
