Search the function:

ACMD(do_dice)
{
	char arg1[256], arg2[256];
	int start = 1, end = 100;

	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

	if (*arg1 && *arg2)
	{
		start = atoi(arg1);
		end = atoi(arg2);
	}
	else if (*arg1 && !*arg2)
	{
		start = 1;
		end = atoi(arg1);
	}

	end = MAX(start, end);
	start = MIN(start, end);

	int n = number(start, end);
	
	if (ch->GetParty())
		ch->GetParty()->ChatPacketToAllMember(CHAT_TYPE_INFO, LC_TEXT("%s님이 주사위를 굴려 %d가 나왔습니다. (%d-%d)"), ch->GetName(), n, start, end);
	else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("당신이 주사위를 굴려 %d가 나왔습니다. (%d-%d)"), n, start, end);
}

Change in:

#ifdef ENABLE_DICE_COMMAND_RENEW
ACMD(do_dice)
{
	int start = 1, end = 100;
	int n = number(start, end);
	
	if (ch->GetParty())
		ch->GetParty()->ChatPacketToAllMember(CHAT_TYPE_INFO, "%s threw the dice.He/she received %d (%d-%d).", ch->GetName(), n, start, end);
	else
		ch->ChatPacket(CHAT_TYPE_INFO, "You threw the dice and received %d (%d-%d).", n, start, end);
}
#else
ACMD(do_dice)
{
	char arg1[256], arg2[256];
	int start = 1, end = 100;

	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));

	if (*arg1 && *arg2)
	{
		start = atoi(arg1);
		end = atoi(arg2);
	}
	else if (*arg1 && !*arg2)
	{
		start = 1;
		end = atoi(arg1);
	}

	end = MAX(start, end);
	start = MIN(start, end);

	int n = number(start, end);
	
	if (ch->GetParty())
		ch->GetParty()->ChatPacketToAllMember(CHAT_TYPE_INFO, LC_TEXT("%s님이 주사위를 굴려 %d가 나왔습니다. (%d-%d)"), ch->GetName(), n, start, end);
	else
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("당신이 주사위를 굴려 %d가 나왔습니다. (%d-%d)"), n, start, end);
}
#endif
