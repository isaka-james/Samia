# Samia HTTP/3 Server

## Prerequisites

Before using the server, generate self-signed SSL certificates by running this command in the `config` folder:

```bash
openssl req -newkey rsa:2048 -nodes -keyout key.pem -x509 -days 365 -out cert.pem
```

## To Run Server

1. Clone the repository:

```bash
git clone https://github.com/isaka-james/Samia.git
```

2. Change to the project directory:

```bash
cd Samia
```

3. Create a build directory and navigate to it:

```bash
mkdir build && cd build
```

4. Generate the build files using CMake:

```bash
cmake ..
```

5. Build the project:

```bash
make
```

6. Run the server:

```bash
./Samia
```

## Testing

Use `curl` to send a request to the server:

```bash
curl -v --http3 https://localhost:443 --insecure
```
