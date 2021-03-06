//
//  EKCalendar.h
//  EventKit
//
//  Copyright 2009-2010 Apple Inc. All rights reserved.
//

#import <EventKit/EventKitDefines.h>
#import <EventKit/EKObject.h>
#import <EventKit/EKTypes.h>

@class EKEventStore, EKSource, NSColor;

/*!
    @class       EKCalendar
    @abstract    The EKCalendar class represents a calendar for events.
*/
EVENTKIT_CLASS_AVAILABLE(10_8, 4_0)
@interface EKCalendar : EKObject

/*!
    @method     calendarForEntityType:
    @abstract   Creates a new autoreleased calendar that may contain the given entity type.
    @discussion You can only create calendars that accept either reminders or events via our API. 
                However, other servers might allow mixing the two (though it is not common).
 
    @param      entityType    The entity type that this calendar may support.
    @param      eventStore    The event store in which to create this calendar.
 */
+ (EKCalendar *)calendarForEntityType:(EKEntityType)entityType eventStore:(EKEventStore *)eventStore __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_6_0);

/*!
    @property   source
    @abstract   The source representing the 'account' this calendar belongs to.
                This is only settable when initially creating a calendar and then
                effectively read-only after that. That is, you can create a calendar, 
                but you cannot move it to another source.
*/
@property(nonatomic, retain) EKSource        *source;

/*!
    @property   calendarIdentifier
    @abstract   A unique identifier for the calendar. It is not sync-proof in that a full
                sync will lose this identifier, so you should always have a back up plan for dealing
                with a calendar that is no longer fetchable by this property, e.g. by title, type, color, etc.
                Use [EKEventStore calendarWithIdentifier:] to look up the calendar by this value.
*/
@property(nonatomic, readonly) NSString         *calendarIdentifier __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_5_0);

/*!
    @property   title
    @abstract   The title of the calendar.
*/
@property(nonatomic, copy)     NSString          *title;

/*!
    @property   type
    @abstract   The type of the calendar as a EKCalendarType. This is actually based on
                what source the calendar is in, as well as whether it is a subscribed calendar.
    @discussion CalDAV subscribed calendars have type EKCalendarTypeCalDAV with isSubscribed = YES. 
*/
@property(nonatomic, readonly)     EKCalendarType     type;

/*!
    @property   allowsContentModifications
    @abstract   Represents whether you can this add, remove, or modify items in this calendar.
*/
@property(nonatomic, readonly) BOOL allowsContentModifications;

/*!
    @property   subscribed
    @abstract   YES if this calendar is a subscribed calendar.
*/
@property(nonatomic, readonly, getter=isSubscribed) BOOL subscribed __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_5_0);

/*!
    @property   immutable
    @abstract   If this is set to YES, it means you cannot modify any attributes of
                the calendar or delete it. It does NOT imply that you cannot add events 
                or reminders to the calendar.
*/
@property(nonatomic, readonly, getter=isImmutable) BOOL immutable __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_5_0);

/*!
    @property   color
    @abstract   Returns the calendar color as a NSColor.
*/
@property(nonatomic, copy) NSColor *color;

/*!
    @property   supportedEventAvailabilities
    @discussion Returns a bitfield of supported event availabilities, or EKCalendarEventAvailabilityNone
                if this calendar does not support setting availability on an event.
*/
@property(nonatomic, readonly) EKCalendarEventAvailabilityMask supportedEventAvailabilities;

/* 
    @property   allowedEntityTypes
    @discussion Returns the entity types this calendar can contain. While our API only allows creation
                of single-entity calendars, other servers might allow mixed-entity calendars.
 */
@property(nonatomic, readonly) EKEntityMask allowedEntityTypes __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_6_0);

@end
