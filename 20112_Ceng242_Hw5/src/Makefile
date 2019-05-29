SOURCES = Message.cpp MessageBox.cpp MessageClient.cpp Filters.cpp Actions.cpp Folder.cpp
HEADERS = Message.h MessageBox.h MessageClient.h Filters.h Actions.h Exception.h Filter.h Action.h Folder.h
INPUTS = inputs

all: sample

sample: sample.cpp $(SOURCES) $(HEADERS)
	g++ -o sample sample.cpp $(SOURCES)

