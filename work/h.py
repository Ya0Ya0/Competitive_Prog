import json
from datetime import datetime, timedelta
def get_user_input(question):
    """Simulates user input for testing."""
    responses = {
        "Are you experiencing any of the following symptoms: Nipple pain, discharge, lump?": "no",
        "Do you have breast implants? 'yes' or 'no'": "yes",
        "What date and time of appointment would best suit you?": "May 8 2pm",
    }
    return responses.get(question, "")
def booking_assistant(user_input):
    # Ask about symptoms
    symptoms_response = user_input("Are you experiencing any of the following symptoms: Nipple pain, discharge, lump?")
    symptoms = [s.strip() for s in symptoms_response.lower().split(',') if s.strip()]
    
    if symptoms:
        return "excluded"
    
    # Ask about breast implants
    breast_implants = user_input("Do you have breast implants? 'yes' or 'no'").lower()
    
    # Ask about appointment date and time
    appointment_response = user_input("What date and time of appointment would best suit you?")
    
    # Parse the appointment date and time
    today = datetime(2023, 5, 5)  # Given current date
    appointment_datetime = parse_datetime(appointment_response, today)
    
    # Prepare the JSON output
    output = {
        "symptoms": symptoms,
        "breast_implants": breast_implants,
        "requested_appointment_datetime": appointment_datetime.isoformat()
    }
    
    return json.dumps(output, indent=2)

def parse_datetime(date_string, today):
    words = date_string.lower().split()
    
    if 'next' in words:
        if 'monday' in words:
            days_ahead = 7 - today.weekday()
        elif 'tuesday' in words:
            days_ahead = (1 - today.weekday() + 7) % 7
        elif 'wednesday' in words:
            days_ahead = (2 - today.weekday() + 7) % 7
        elif 'thursday' in words:
            days_ahead = (3 - today.weekday() + 7) % 7
        elif 'friday' in words:
            days_ahead = (4 - today.weekday() + 7) % 7
        elif 'saturday' in words:
            days_ahead = (5 - today.weekday() + 7) % 7
        elif 'sunday' in words:
            days_ahead = (6 - today.weekday() + 7) % 7
        else:
            days_ahead = 7
        
        appointment_date = today + timedelta(days=days_ahead)
    else:
        # Assume it's a date in the format "YYYY-MM-DD"
        appointment_date = datetime.strptime(words[0], "%Y-%m-%d")
    
    # Extract time
    time_str = words[-1] if len(words) > 1 else "9:00"  # Default to 9:00 if no time provided
    hour, minute = map(int, time_str.split(':'))
    
    return appointment_date.replace(hour=hour, minute=minute)
result = booking_assistant(get_user_input)
print(result)