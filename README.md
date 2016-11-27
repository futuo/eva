#What is eva?

Eva is a data base that relies on event sources to store data. This means that
the database keeps a command log from which all data can be reconstructed. The
added benefit of keeping such log is that versioning and historical aggregation 
functions come free of charge. Moreover, since the command log is immutable,
entities can be constructed and updated as the commands flow into the system,
maintining a "views cache" over the data, that never becomes outdated.

Also, eva architecture was though to comply with a Command Query Responsability 
Segregation (CQRS) approach. This means that you can define a schema for
writing operations and a schema for reading data. This gives both commands and
views semantic value, making it possible to configure eva in accordance with
your application's business logic.

#Installation

In order to build the project, clone it and compile it with:
```
autoreconf --install
./configure
make
```
The executable should be under eva-engine/eva

#Architecture

Eva is divided in two modules, the command-engine and the view-engine. Since
many of the algorithms, data structures and general logic will be similar among
the two modules, there's also a third modules named commons. Finally the 
integration between all three modules is what we'll call the eva-engine.

For the time being, clients for eva-engine are out of the scope of this 
project.

##command-engine
- Read and enforce the command schema definition
- Accept and validate commands
- Store commands in indexes and allow efficient searching
- Send update events to the view engine

##view-engine
- Read and act uppon the view schema definition
- Accept and validate queries
- Maintain the caches in indexes and allow efficient searching
- Act uppon data update events triggered by the command engine

