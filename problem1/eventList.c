#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList ->isEmpty = 1;
    eventList ->head = NULL;
    eventList ->last = NULL;
    return eventList;

}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *evtTemp = this->head;
    if(this->isEmpty == 0)
    {
        while (evtTemp != NULL)
        {
            if(strcmp(name, evtTemp->eventName) == 0)
            {
                return evtTemp;
            }
            evtTemp = evtTemp->next;
        }
    }
    evtTemp = NULL;
    return evtTemp;

}

void AddEvent(EventList *this, Event *event)
{
    if(this->isEmpty == 1)
    {
        this->isEmpty = 0;
        this->head = event;
        this->last = event; 
    }
    else
    {
        Event *evtTemp = this->head;
        
        while(evtTemp != NULL)
        {
            if(strcmp(event->eventName, evtTemp->eventName) == 0)
            {
                return;
            }    
            evtTemp = evtTemp->next;
        }
        this->last->next = event;
        this->last = event;  
    }
    
}

void RemoveEvent(EventList *this, char *name)
{
    if (this->isEmpty == 0)
    {       
        if(strcmp(name, this->head->eventName) == 0)
        {
            Event *evtTemp = this->head;
            if(this->head->next == NULL)
            {
                this->head = NULL;
                this->last = NULL;
                this->isEmpty = 1;
                DestroyEvent(this->head);
            }
            else
            {
                this->head = this->head->next;
                DestroyEvent(evtTemp);
            }
            
        }
        else if (strcmp(name, this->last->eventName) == 0)
        {
            Event *evtTemp = this->head;
            while (evtTemp->next != NULL)
            {
                if(evtTemp->next->next == NULL)
                {
                    this->last = evtTemp->next;
                    evtTemp->next = NULL;
                    break;
                }
                evtTemp = evtTemp->next;
            }
            DestroyEvent(this->last);
        }
        else 
        {
            Event *evtAct = this->head;
            Event  *evtN = this->head;
            u_int8_t bool = 0;
            while (evtAct->next != NULL)
            {
                if(strcmp(name, evtAct->next->eventName) == 0)
                {
                    evtN = evtAct->next;
                    evtAct->next = evtAct->next->next;
                    bool = 1;
                    break;
                }
                evtAct = evtAct->next;
            }
            if (bool == 1)
            {
                DestroyEvent(evtN);
            }         
        }        
    }
}

void ListEvents(EventList *this)
{
    Event *actEvent = this->head;

    if(this->isEmpty == 1)
    {
        printf("empty\n");
    }
    else 
    {
        printf("%s\n",this->head->eventName);
        while (actEvent->next != NULL)
        {
            actEvent = actEvent->next;
            printf("%s\n",actEvent->eventName); 
        }
    }
}