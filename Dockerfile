FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential gdb && rm -rf /var/lib/apt/lists/*

WORKDIR /taskforgeApp

COPY src/ .

RUN make

CMD ["./taskforge"]