#include "event_handler.h"

//better use boost::ptr_map instead of std::map
EventHandler::~EventHandler()
{
	Handlers::iterator it = _handlers.begin();
	while(it != _handlers.end())
	{
		delete it->second;
		++it;
	}
	_handlers.clear();
}

void EventHandler::handleEvent(const Event* event)
{
	Handlers::iterator it = _handlers.find(TypeInfo(typeid(*event)));
	if(it != _handlers.end())
	{
		it->second->exec(event);
	}
}