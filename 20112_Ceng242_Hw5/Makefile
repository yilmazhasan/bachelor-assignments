SOURCES = Message.cpp MessageBox.cpp MessageClient.cpp Filters.cpp Actions.cpp
HEADERS = Message.h MessageBox.h MessageClient.h Filters.h Actions.h Exception.h Filter.h Action.h
INPUTS = inputs

all: sample

sample: sample.cpp $(SOURCES) $(HEADERS)
	g++ -o sample sample.cpp $(SOURCES)

