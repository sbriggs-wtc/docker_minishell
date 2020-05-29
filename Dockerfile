FROM debian
LABEL maintainer="sbriggs"
RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y build-essential valgrind emacs htop && \
    mkdir /minishell

WORKDIR /minishell
ENTRYPOINT /bin/bash

#apt-get install -y --no-install-recommends \
#apt-cache search valgrind
#valgrind --leak-check=full ./minishell
#docker stop $(docker ps -a -q) && docker ps -a
#docker rm $(docker ps -a -q)
#docker exec -it minishell bash

#BUILD CONTAINER LIKE THIS: (emacs)
#docker build --tag debian_c .

#RUN LIKE THIS:
#docker run -it --rm --mount type=bind,source=$(pwd)/minishell,destination=/minishell --name minishell debian_c
