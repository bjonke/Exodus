#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <map>
#include "type_info.h"

class Event
{
protected:
	virtual ~Event() {};
};

class HandlerFunctionBase
{
public:
	virtual ~HandlerFunctionBase() {};
	void exec(const Event* event) {call(event);}

private:
	virtual void call(const Event*) = 0;
};


template <class T, class EventT>
class MemberFunctionHandler : public HandlerFunctionBase
{
public:
	typedef void (T::*MemberFunc)(EventT*);
	MemberFunctionHandler(T* instance, MemberFunc memFn) : _instance(instance), _function(memFn) {};

	void call(const Event* event)
	{
		(_instance->*_function)(static_cast<EventT*>(event));
	}

private:
	T* _instance;
	MemberFunc _function;
};


class EventHandler
{
public:
	~EventHandler();
	void handleEvent(const Event*);

	template <class T, class EventT>
	void registerEventFunc(T*, void (T::*memFn)(EventT*));

private:
	typedef std::map<TypeInfo, HandlerFunctionBase*> Handlers;
	Handlers _handlers;
};


template <class T, class EventT>
void EventHandler::registerEventFunc(T* obj, void (T::*memFn)(EventT*))
{
	_handlers[TypeInfo(typeid(EventT))]= new MemberFunctionHandler<T, EventT>(obj, memFn);
}

#endif